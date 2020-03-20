with open("/dev/ttyACM0", "r") as f:
    while 1:
        print(f.readline(), end="")