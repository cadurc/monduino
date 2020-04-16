// Branchement :
// Servo en 3
// Potentiomètre en A0


// On fait appel à la bibliothèque qui sait comment gérer les servomoteurs
#include <Servo.h>

// Création des variables pour mon mappage
int buteee_gauche = 180;
int butee_droite = 0;

// création de la variable qui va stocker la lecture de la broche analogique
int lecture_potar = 0;

// création de la vatiable qui va contenir l'angle à donner au servomoteur (après mappage ou règle de 3)
int consigne_angle_servo = 0;

// création de l'objet servo qui va s'appeler par la suite servo_3
Servo servo_3;

// Séquence d'initialisation
void setup()
{
  pinMode(A0, INPUT); // Je définie ma broche A0 en tant qu'entrée analogique
  servo_3.attach(3); // J'indique que j'ai branché le servo sur la broche 3

  Serial.begin(9600); // Je démarre la communication serie pour avoir les informations dans mon terminal

}

// Programme principal qui tourne en boucle
void loop()
{
    lecture_potar = analogRead(A0); // Je lis la valeur en A0 et la stocke dans ma variable lecture_potar
    
    // Je fais un mappage (règle de 3) de ma valeur d'origine qui va de 0 à 1023 vers mes butées
    consigne_angle_servo = (map(lecture_potar, 0, 1023, buteee_gauche, butee_droite));

    servo_3.write(consigne_angle_servo); // J'envoie la consigne au servo de bouger vers l'angle consigne_angle_servo

    Serial.println(consigne_angle_servo); // J'imprime la valeur dans mon moniteur

}
