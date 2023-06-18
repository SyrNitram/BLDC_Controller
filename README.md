# BLDC_Controller
Contrôleur de moteur BLDC développé dans le cadre d'un projet 3DN de L'ENSEA. 

## Fonctionnement géneral

![Synoptique](https://github.com/SyrNitram/BLDC_Controller/assets/71044010/b43cae5c-fbc5-4354-9405-3ffb3aed1575)

Le contrôleur est conçu autour d'un DRV8323RS de chez TI. Il s'agit d'un pilote de grille de MOSFET intelligent et configurable en SPI. Les différents modes de contrôle simplifient le pilotage du moteur BLDC et évitent les erreurs pouvant causer des dommages à la carte. Les fonctions supplémentaires les plus utiles sont la gestion des courants de grille et des temps morts. La version que nous avons choisie intègre également trois amplificateurs différentiels qui nous permettent de mesurer le courant facilement, ainsi qu'un régulateur Buck.

Le microcontrôleur gère le contrôle du moteur en faisant varier un rapport cyclique, on peut y programmer un contrôle en vitesse ou en position par exemple.

La carte communique vers l'extérieur grâce à un bus CAN. Ce bus est robuste et ne sera pas perturbé par les éventuelles perturbations électromagnétiques générées par le moteur. Deux connecteurs permettent de chaîner facilement les cartes entre-elles. Il ne faut pas oublier les résistances de terminaisons qui sont primordiales pour le fonctionnement du bus CAN.

La mesure de courant est réalisée à l'aide de 3 résistances de shunt de faible valeur dont les tensions à leurs bornes sont amplifiées par l'amplificateur du DRV8323. Cette tension amplifiée est ensuite lue par l'ADC du microcontrôleur. 


## Organisation du repo :

1-HARDWARE

	Projet Kicad
	
2-SOFTWARE

	Projet STM32CubeIDE
	
3-DOCUMENTS

	1-Gestion_projet
		Liste des commandes passées
		Liste des tâches à réaliser
	2-Conception
		Liste des fonctions à développer et le moyen d'y arriver
		Notes prises lors de la conception
	3-Annexes
		Datasheets composants
		Design guides
		Extrait de rapport de projet industriel
