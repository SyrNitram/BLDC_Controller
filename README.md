# BLDC_Controller
<p align="justify"> Contrôleur de moteur BLDC développé dans le cadre d'un projet 3DN 2023 de L'ENSEA. 

Tutoré par Laurent FIACK et Nicolas PAPAZOGLOU.

Réalisé par Alex BADAOUI, Jérôme DUPOUTS, Hugo LE COZ, Etienne PARMENTIER et Martin RYS.
</p>

<p align="center">
<img src="https://github.com/SyrNitram/BLDC_Controller/assets/71044010/296c8066-6a76-4669-9487-880f44aea552">
</p>

## Contexte

<p align="justify">
Ce projet s'inscrit dans un projet plus ambitieux de plate-forme mobile lancé par M. Laurent FIACK. L'objectif à terme est de réaliser des plates-formes mobiles permettant à une personne équipée d'un casque Vr de pouvoir se déplacer dans l'espace sans jamais sortir de la zone de jeu réel. Ces plateformes seront également escamotables permettant de simuler un escalier pour le joueur par exemple. La première brique de ce projet est d'être capable de piloter des moteurs suffisamment puissants pour déplacer une personne et de manière assez précise pour éviter les accélérations brusques qui feraient chuter l'utilisateur. 
</p>

<p align="justify">
En s'inspirant d'un skateboard électrique nous avons pu avoir un ordre de grandeur sur la puissance à fournir, et donc sur le dimensionnement des moteurs et du système. D'autant plus qu'ici la vitesse et l'accélération seront faibles et les mouvements ne seront pas prolongés.
</p>


<div align="center">
<video src="https://github.com/SyrNitram/BLDC_Controller/assets/71044010/428e7cd6-9636-413b-9740-a20cd94b0979">
</div>



## Fonctionnement géneral

<p align="center">	
<img src="https://github.com/SyrNitram/BLDC_Controller/assets/71044010/b43cae5c-fbc5-4354-9405-3ffb3aed1575">
</p>

<p align="justify">
Le contrôleur est conçu autour d'un DRV8323RS de chez TI. Il s'agit d'un pilote de grille de MOSFET intelligent et configurable en SPI. Les différents modes de contrôle simplifient le pilotage du moteur BLDC et évitent les erreurs pouvant causer des dommages à la carte. Les fonctions supplémentaires les plus utiles sont la gestion des courants de grille et des temps morts. La version que nous avons choisie intègre également trois amplificateurs différentiels qui nous permettent de mesurer le courant facilement, ainsi qu'un régulateur Buck.
</p>

<p align="center">	
<img src="https://github.com/SyrNitram/BLDC_Controller/assets/71044010/de5bca9e-0acd-4807-a2ce-c866d5b3d1c0">
</p>

<p align="justify">
Le microcontrôleur gère le contrôle du moteur en faisant varier un rapport cyclique, on peut y programmer un contrôle en vitesse ou en position par exemple. La carte communique vers l'extérieur grâce à un bus CAN. Ce bus est robuste et ne sera pas perturbé par les éventuelles perturbations électromagnétiques générées par le moteur. Deux connecteurs permettent de chaîner facilement les cartes entre-elles. Il ne faut pas oublier les résistances de terminaisons qui sont primordiales pour le fonctionnement du bus CAN. La mesure de courant est réalisée à l'aide de 3 résistances de shunt de faible valeur dont les tensions à leurs bornes sont amplifiées par l'amplificateur du DRV8323. Cette tension amplifiée est ensuite lue par l'ADC du microcontrôleur. 
</p>



<div align="center">
<video src="https://github.com/SyrNitram/BLDC_Controller/assets/71044010/bd33bcf4-3d07-498e-9aa8-d4169d70426a">
</div>


<p align="center">
 
<img src="https://github.com/SyrNitram/BLDC_Controller/assets/71044010/de7259f5-9df3-481a-a4ee-6529233a8884" >

<img src="https://github.com/SyrNitram/BLDC_Controller/assets/71044010/aeea6015-c81e-4267-8ce4-b2f76976af69">

<img src="https://github.com/SyrNitram/BLDC_Controller/assets/71044010/c2661d72-d13c-4ad0-9c08-9f6946fd94df">

</p>

## Organisation du projet

1-HARDWARE

	Projet Kicad
	
2-SOFTWARE

	Projet STM32CubeIDE
	
3-DOCUMENTS

	1-Gestion_projet
		Liste des commandes passées
		Liste des tâches à réaliser
  		Schéma synoptique
	2-Conception
		Liste des fonctions à développer et le moyen d'y arriver
		Notes prises lors de la conception
	3-Annexes
		Datasheets composants
		Design guides
		Extrait de rapport de projet industriel
