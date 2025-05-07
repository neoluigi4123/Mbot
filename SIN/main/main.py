from communication import POST, GET
from time import sleep

while True:
        # list of different Msg:
        # - 'ping': check system availability
        # - 'get_dist': get ultrasensor measures
        # - 'get_dist_left': get ultrasensor LEFT measures
        # - 'get_dist_right': get ultrasensor RIGHT measures
 
        msg = input("Msg: ")
        POST(msg)
        for i in range(10):
                result = GET()
                if result is None:
                        sleep(0.5)
                else:
                        if result  == "Hello from Arduino":
                                print(result)
                                break
                        if "distance" in result:
                                print(result)
                                break
