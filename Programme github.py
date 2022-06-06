#Enzo Masson
#Ce programme renvoie le nombre de diviseur d'un nombre choisi par l'utilisateur

def diviseurs(nombre):
    liste = []
    for i in range(1,nombre+1):
        if nombre%i == 0:
            liste.append(i)
    return liste

def premier_ou_pas(liste):
    if len(liste) == 2:
        return "Ce nombre est premier."
    else:
        return "Ce nombre n'est pas premier."

nombre = int(input("Entrez un chiffre entier dont vous voulez connaître le nombre de diviseurs : "))
print("Les diviseurs de",nombre,"sont",diviseurs(nombre))
print(premier_ou_pas(diviseurs(nombre)))


#nb = 'ok'
#Liste = []
#while nb != '':
#    nb = int(input("Entrer un chiffre : "))
#    Liste.append()

    