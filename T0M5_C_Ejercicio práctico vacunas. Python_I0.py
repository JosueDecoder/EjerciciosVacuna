# coding=utf-8

fechaF = raw_input("Ingrese fecha de nacimiento (dd/mm/yyyy): ")

#Validaci��n de la Fecha de nacimiento ingresada
try:
    from datetime import datetime
    fechaF = datetime.strptime(fechaF, "%d/%m/%Y")
except:
  print("La fecha ingresada no es correcta el formato debe ser (dd/mm/yyyy)")
  exit()
  
anioF = fechaF.year
mesF  = fechaF.month
diaF  = fechaF.day

#Fecha actual
fechaH = datetime.today()

anioH = fechaH.year
mesH  = fechaH.month
diaH  = fechaH.day


mesAdicional = 0
if (diaF > diaH):
    import calendar
    ultimoDia = calendar.monthrange(anioF, mesF)[1]
    diaH = diaH + ultimoDia
    mesAdicional =  1

dias = diaH - diaF


anioAdicional = 0
if (mesF > mesH):
    mesH= mesH + 12
    anioAdicional = 1

meses = mesH  - (mesF + mesAdicional)
anios = anioH - ( anioF + anioAdicional)


print("Tienes "+str(anios)+" años "+str(meses)+" meses "+str(dias) +" días")

if(anios > 65):
    print("Tienes más de 65 años, eres candidato para la vacuna.")
elif (anios == 64 and meses >= 6):
        print("En menos de 6 meses cumples 65 años, te pondremos en lista de espera.")
else:
        print("No eres candidato para la vacuna.")