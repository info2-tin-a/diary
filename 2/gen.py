""" Data generation """
import datetime
import random
start_date = datetime.date(2010, 1, 1)
end_date = datetime.date(2022,2,1)

with open('data.csv', 'w') as fp:
    fp.writelines(["Date,Ville,Température,Humidité"])
    for i in range(1000):
        date = (start_date + datetime.timedelta(
            days=random.randrange((end_date - start_date).days))
        ).strftime('%Y-%m-%d')
        temp = random.randint(-10, 36)
        moisture = random.randint(0, 100)
        city = random.choice(["Yverdon", "Lausanne", "Geneve", "Berne"])
        fp.write(f"{date},{temp},{moisture},{city}\n")
