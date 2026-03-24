# Vérificateur de Password 2.0

Outil de cybersécurité en ligne de commande écrit en C.

## Fonctionnalités

- Analyse la force d'un password (longueur, majuscules, chiffres, caractères spéciaux)
- Compte les caractères d'une saisie
- Vérifie si un password est dans une liste de passwords fuités

## Prérequis

- GCC ou Clang
- Une wordlist au format `.txt` (recommandé : SecLists sur GitHub)

## Compilation
```bash
gcc main.c -o verificateur
```

## Utilisation

Placez votre fichier wordlist dans le même dossier que le programme et renommez-le `100k-passwords-NCSC.txt`.

Lancez le programme :
```bash
./verificateur
```

## Wordlist recommandée

Téléchargez la liste depuis SecLists :
[https://github.com/danielmiessler/SecLists/blob/master/Passwords/Common-Credentials/100k-most-used-passwords-NCSC.txt](https://github.com/danielmiessler/SecLists/blob/master/Passwords/Common-Credentials/100k-most-used-passwords-NCSC.txt)

---
Projet d'apprentissage — AthoHck • 2026
