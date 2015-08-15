import sys

x='si'

while x=='si':
    tecla = sys.stdin.read(1)
    if tecla != 's':
        print 'Has presionado ', tecla
    else:
        x='no'
        print 'Se rompe el bucle'
