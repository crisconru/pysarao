from serial import Serial
from serial.tools.list_ports import comports as stlpc

port = ''
for dispositivo in stlpc():
    if 'Arduino' in dispositivo.manufacturer:
        print('Encontrado Arduino en {}'.format(dispositivo.device))
        port = dispositivo.device
        break
cx = Serial(port)
if cx.is_open:
    print('no se ha podido abrir comunicacion')