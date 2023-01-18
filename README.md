# Drivers et programme de récupération des données

Les drivers sont la source de données du projet.

## Compilation des drivers

```bash
make
```

## Ajout d'un driver au kernel

```bash
insmod driverHygro.ko
```

## Lancement du programme python

```bash
python3 meteoSD.py
```


## Fonctionnement

Les drivers permettent de générer des chiffres aléatoires qui sont ensuite récupérés toutes les 15 secondes par le programme de récupération.
Les chiffres sont ensuite compilés par le programme et ajoutés dans un fichier CSV nommé data-weather-station.csv.

@reboot python3 /home/RaspberryPi/weather-station-drivers/code/meteoSD.py > /home/RaspberryPi/weather-station-drivers/code/meteoSDlog.txt


