import pygame
import math
import ui

# G0 -> Rapid move
# G1 -> Linear move
# G2 -> CW arc
# G3 -> CCW arc

pygame.init()

screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()
font = pygame.font.SysFont("Source Code Pro", 20)


class Motor():
    def __init__(self):
        self.position = 0
        pass

    def step(self, ccw):
        if ccw is False:
            self.position += 1
        else:
            self.position -= 1

    def get_position(self):
        return self.position

    def set_position(self, position):
        self.position = position


def move_rapid(x0, y0, x1, y1):
    buffer = []
    while x0 != x1 or y0 != y1:
        command = [0, 0, 0]
        if x1 > x0:
            command[0] = 1
        elif x1 < x0:
            command[0] = -1
        if y1 > y0:
            command[1] = 1
        elif y1 < y0:
            command[1] = -1
        x0 += command[0]
        y0 += command[1]
        buffer.append(command)
    return buffer


def move_linear(x0, y0, x1, y1):
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)

    if dy > dx:
        dx, dy = dy, dx

    buffer = []
    y = 0
    for x in range(dx):
        command = [0, 0, 0]

        if (dy * (x+1) - dx * (y + 0.5)) > 0:
            command = [1, 1, 0]
            y += 1
        else:
            command = [1, 0, 0]

        if abs(y1-y0) > abs(x1-x0):
            command = [command[1], command[0], 0]
            if x1 < x0:
                command[0] *= -1
            if y1 < y0:
                command[1] *= -1
        else:
            command = command
            if x1 < x0:
                command[0] *= -1
            if y1 < y0:
                command[1] *= -1

        buffer.append(command)

    return buffer


def move_arc(x, y, i, j):
    buffer = []

    # Calculate circle radius
    r = math.sqrt((x ** 2) + (y ** 2) - ((i) ** 2) - ((j) ** 2))
    print(r)

    # Solve Bresenham's algorithm for first octant
    a = 0
    b = int(r)
    while a != b:
        if (a+1)**2 + (b+0.5)**2 - r**2 > 0:
            b -= 1
            buffer.append([1, 1, 0])
        else:
            buffer.append([1, 0, 0])
        a += 1

    # Copy and rotate first octant eight times to build full circle
    temp_buffer = []
    temp_buffer += buffer
    temp_buffer += list(map(lambda x: [x[1], x[0], x[2]], reversed(buffer)))
    temp_buffer += list(map(lambda x: [-x[1], x[0], x[2]], buffer))
    temp_buffer += list(map(lambda x: [-x[0], x[1], x[2]], reversed(buffer)))
    temp_buffer += list(map(lambda x: [-x[0], -x[1], x[2]], buffer))
    temp_buffer += list(map(lambda x: [-x[1], -x[0], x[2]], reversed(buffer)))
    temp_buffer += list(map(lambda x: [x[1], -x[0], x[2]], buffer))
    temp_buffer += list(map(lambda x: [x[0], -x[1], x[2]], reversed(buffer)))
    buffer = temp_buffer

    start_angle = math.degrees(math.atan(-j/-i))
    end_angle = math.degrees(math.atan(y/x))
    print(start_angle, end_angle)

    return buffer


def command_parser(line):
    segments = line.split(" ")

    args = {}
    for segment in segments[1:]:
        args[segment[0]] = int(segment[1:])

    if segments[0] == "G0":
        return move_rapid(0, 0, args["X"], args["Y"])
    elif segments[0] == "G1":
        return move_linear(0, 0, args["X"], args["Y"])
    elif segments[0] == "G2":
        return move_arc(args["X"], args["Y"], args["R"])
    else:
        return []


motor_x = Motor()
motor_y = Motor()
motor_z = Motor()

buffer = []
buffer_counter = 0
buffer_run = False
buffer_origin = (0, 0, 0)

command_line = False

tick_keyboard = pygame.time.get_ticks()
tick_buffer = pygame.time.get_ticks()

while True:
    screen.fill("black")

    # Plotters
    ui.XYPlotterElement(screen, 10, 10, 400, 580).draw(
            motor_x.get_position(),
            motor_y.get_position())
    ui.ZPlotterElement(screen, 420, 10, 40, 580).draw(motor_z.get_position())

    # Motors
    ui.MotorElement(screen, 470, 10, 150, 150, "X").draw(
            motor_x.get_position())
    ui.MotorElement(screen, 470+160, 10, 150, 150, "Y").draw(
            motor_y.get_position())
    ui.MotorElement(screen, 470, 170, 150, 150, "Z").draw(
            motor_z.get_position())

    # Status
    ui.TextElement(screen, 470, 330, 18).draw(f'BL: {len(buffer)}')
    ui.TextElement(screen, 470, 350, 18).draw(f'BC: {buffer_counter}')
    ui.TextElement(screen, 470, 370, 18).draw(f'BR: {buffer_run}')
    ui.TextElement(screen, 470, 390, 18).draw(f'BO: {buffer_origin}')

    # Events
    events = pygame.event.get()
    for event in events:
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_r:
                buffer = []
                buffer += move_arc(-70, 10, -40, -30)
                # buffer += move_arc(100, 100, 200, 0)

            elif event.key == pygame.K_SLASH:
                command_line = True

            elif event.key == pygame.K_SPACE:
                buffer_run = not buffer_run
                if buffer_run is True and buffer_counter == 0:
                    buffer_origin = (
                            motor_x.get_position(),
                            motor_y.get_position(),
                            motor_z.get_position())
                if buffer_run is True and buffer_counter > 0:
                    # Calculate continue point coordinates
                    continue_point = [buffer_origin[0], buffer_origin[1], 0]
                    for i in range(buffer_counter):
                        continue_point[0] += buffer[i][0]
                        continue_point[1] += buffer[i][1]
                        continue_point[2] += buffer[i][2]

                    # Modify buffer
                    new_buffer = move_rapid(motor_x.get_position(), motor_y.get_position(), continue_point[0], continue_point[1])
                    new_buffer += buffer[buffer_counter:]
                    buffer = new_buffer
                    buffer_counter = 0

    # Command line
    if command_line is True:
        command = input(":")

        if command == "":
            command_line = False
        else:
            buffer.extend(command_parser(command))

    # Keyboard
    if pygame.time.get_ticks() - tick_keyboard >= 10:
        tick_keyboard = pygame.time.get_ticks()

        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            motor_x.step(True)
        elif keys[pygame.K_RIGHT]:
            motor_x.step(False)
        if keys[pygame.K_UP]:
            motor_y.step(True)
        elif keys[pygame.K_DOWN]:
            motor_y.step(False)
        if keys[pygame.K_COMMA]:
            motor_z.step(True)
        elif keys[pygame.K_PERIOD]:
            motor_z.step(False)

    # Buffer
    if pygame.time.get_ticks() - tick_buffer >= 10:
        tick_buffer = pygame.time.get_ticks()

        if len(buffer) > 0 and buffer_run is True:
            if buffer_counter < len(buffer):
                current = buffer[buffer_counter]
                buffer_counter += 1

                if current[0] > 0:
                    motor_x.step(False)
                elif current[0] < 0:
                    motor_x.step(True)
                if current[1] > 0:
                    motor_y.step(False)
                elif current[1] < 0:
                    motor_y.step(True)
                if current[2] > 0:
                    motor_z.step(False)
                elif current[2] < 0:
                    motor_z.step(True)

            if buffer_counter == len(buffer):
                buffer = []
                buffer_counter = 0
                buffer_run = False
                buffer_origin = (0, 0)

    pygame.display.flip()
    pygame.event.pump()

pygame.quit()
