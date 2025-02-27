import numpy as np
import csv
import matplotlib.pyplot as plt
l = []
with open("datos/merge_datos_10000_1_2025-02-27.csv","r") as _file:
    reader = csv.reader(_file)
    for f in reader:
        l.append(f[1])

l.pop(-1)


arr = np.array(l)


print(arr)
plt.plot(np.arange(len(arr)), arr, marker='o', linestyle='-', color='blue', label='Datos')

# Añadir títulos y etiquetas
plt.title('Grafica de Datos')
plt.xlabel('Índice')
plt.ylabel('Valor')
plt.legend()

# Mostrar la gráfica
plt.grid(True)
plt.show()

