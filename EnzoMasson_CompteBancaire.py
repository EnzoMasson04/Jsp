#Enzo Masson
#class compte bancaire
#Ce programme permet de gérer un compte bancaire
#Version 1

class CompteBancaire:
    
    def __init__(self,nom,numero,solde):
        self.nom = nom
        self.numero = numero
        self.solde = solde
    
    def getNom(self):
        return self.nom
    
    def getNumero(self):
        return self.numero
    
    def getSolde(self):
        return self.solde
    
    def setNom(self,NEWnom):
        self.nom = NEWnom
        print("Le nouveau propriétaire de la carte est :",NEWnom)
    
    def setNumero(self,NEWnumero):
        self.numero = NEWnumero
        print("Les nouveaux numeros de carte sont :",NEWnumero)
    
    def versement(self,versement):
        self.solde += versement
        print("Le nouveau solde de carte est de:",self.solde)
    
    def retrait(self,retrait):
        self.solde -= retrait
        print("Le nouveau solde de carte est de:",self.solde)
    
    def agios(self):
        if self.solde < 0:
            self.solde += (self.solde*0.05)
            print("Le nouveau solde de carte est de :",self.solde)
        else:
            print("Le nouveau solde de carte est de :",self.solde)
    
    def afficher(self):
        print("Le propriétaire de la carte est :",self.nom)
        print("Tes numéros de carte sont :",self.numero)
        print("Ton solde est de :",self.solde)

CarteMaman = CompteBancaire("Papa",123456789,1000)
CartePapa = CompteBancaire("Papa",987654321,200)
CarteMaman.setNom("Maman")
CarteMaman.getNom()
CarteMaman.versement(500)
CartePapa.retrait(300)
CartePapa.agios()
CartePapa.getSolde()
CarteMaman.afficher()
CartePapa.afficher()