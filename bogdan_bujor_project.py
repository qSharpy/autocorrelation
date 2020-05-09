import matplotlib.pyplot as plt
import csv

x = []
y = []

with open('C:\\Users\\Bogdan\\Documents\\Signal Analysis project\\.vscode\\' +
    'Signal Analysis - Autocorrelation\\nottingham-temperature\\nottingham-temperature-out.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

fo = open('C:\\Users\\Bogdan\\Documents\\Signal Analysis project\\.vscode\\' + 
    'Signal Analysis - Autocorrelation\\nottingham-temperature\\nottingham-temperature-out.csv', 'r')
content = fo.readlines()
print content

plt.plot(x,y)
plt.xlabel('Lag') 
plt.ylabel('Autocorrelation')
plt.title('Autocorrelation of monthly temperature\nNottingham Castle, 1920 - 1939')
plt.legend()
plt.show()