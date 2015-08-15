import termios, fcntl, sys, os
fd = sys.stdin.fileno()

oldterm = termios.tcgetattr(fd)
newattr = termios.tcgetattr(fd)
newattr[3] = newattr[3] & ~termios.ICANON & ~termios.ECHO
termios.tcsetattr(fd, termios.TCSANOW, newattr)

oldflags = fcntl.fcntl(fd, fcntl.F_GETFL)
fcntl.fcntl(fd, fcntl.F_SETFL, oldflags | os.O_NONBLOCK)

try:
    while 1:
        try:
            c = sys.stdin.read(1)
           # print "Got character", repr(c)

           
            if c == "s":
               print "Cemtro"
           
            elif c == "a":
               print "Izquierdo"
            elif c == "d":
               print "derecho"
            elif c == "w":
               print "Arriba"

            elif c == "x":
               print "Abajo"


            elif c =="q":
               print "Hasta luego"
               sys.exit(1)


        except IOError: pass
	 
  
	 
finally:
    termios.tcsetattr(fd, termios.TCSAFLUSH, oldterm)
    fcntl.fcntl(fd, fcntl.F_SETFL, oldflags)

