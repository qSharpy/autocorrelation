import matplotlib.pyplot as plt
import csv

x = []
y = []

with open('C:\\Users\\Bogdan\\Documents\\Signal Analysis project\\.vscode\\Signal Analysis - Autocorrelation\\interest-rate\\interest-rate-out.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')
    for row in plots:
        x.append(int(row[0]))
        y.append(float(row[1]))

fo = open('C:\\Users\\Bogdan\\Documents\\Signal Analysis project\\.vscode\\Signal Analysis - Autocorrelation\\interest-rate\\interest-rate-out.csv', 'r')
content = fo.readlines()
print content

plt.plot(x,y)
plt.xlabel('Lag') 
plt.ylabel('Autocorrelation')
plt.title('Autocorrelation of monthly Interest rates\nReserve Bank of Australia\nJan 1969 - Sep 1994')
plt.legend()
plt.show()