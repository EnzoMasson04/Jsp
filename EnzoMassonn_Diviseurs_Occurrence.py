#Enzo Masson
#def diviseurs + premier_ou_pas
#def occurence


def diviseurs(nombre):
    diviseurs = [] #Créé une liste vide
    for i in range(1,nombre+1):
        if nombre%i == 0: #Calcule si le nombre choisi par l'utilisateur possède un reste pour chaque diviseurs compris entre 1 et lui-même inclu
            liste.append(i) #Ajoute le diviseur à la liste 'diviseurs' si le reste est égale à 0
    return liste #Renvoie la liste des diviseurs de 'nombre'

def premier_ou_pas(liste):
    if len(liste) == 2: #Vérifie si le nombre possède 2 diviseurs éxactement
        return "Ce nombre est premier." #Si oui il est premier
    else:
        return "Ce nombre n'est pas premier." #Si non il n'est pas premier

nombre = int(input("Entrez un nombre entier dont vous voulez connaître le nombre de diviseurs : ")) #Demande un nombre entier à l'utilisateur
print("Les diviseurs de",nombre,"sont",diviseurs(nombre))
print(premier_ou_pas(diviseurs(nombre)))
print("")


def occurrence(phrase):
    lettre = {} #Créé un dictionnaire vide
    for i in phrase:
        if i in lettre: #Si la lettre prise par i est déja dans le dictionnaire on ajoute un à sa valeur
            lettre[i] += 1
        else: #Sinon on lui donne 1 comme valeur
            lettre[i] = 1
    return lettre #Renvoie le dictionnaire de lettre(s)

phrase = input("Entrer une phrase dont vous voulez connaître son occurence : ")
print("Voici un dictionnaire contenant les lettres de cette phrase ainsi que leurs occurrences :",occurrence(phrase))
