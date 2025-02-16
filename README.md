# 😎 cryptX

## 🚀 Introduction

**cryptX** est un outil en ligne de commande sous Windows, développé en C++ et conçu à des fins éducatives dans le domaine de la cybersécurité. Ce projet démontre comment un fichier exécutable peut être chiffré, modifié et ensuite déchiffré pour tenter de contourner certains mécanismes de détection des antivirus dans un environnement contrôlé.

> ⚠️ **Important :**  
> Ce projet est strictement destiné à des fins pédagogiques. N'utilisez jamais ces techniques sur des systèmes pour lesquels vous n'avez pas l'autorisation explicite. Travaillez toujours dans un environnement sécurisé (par ex. une machine virtuelle).

---

## ✨ Fonctionnalités

🔐 **Chiffrement XOR** (clé `0xAA`)
🗃️ **Augmentation** de 101 MB de données aléatoires
🔢 **Incrémentation** d'un compteur jusqu'à 100001
⏱️ **Pause** de 101 secondes avec mesure du temps
🖥️ **Déchiffrement et exécution** via l'API Windows

---

## 🛠️ Architecture & Conception

Le projet suit les principes de **Programmation Orientée Objet** et de **Clean Code**. Chaque fonctionnalité est gérée par un composant dédié.

---

## 📋 Prérequis

- 🪟 **Windows 10** (machine virtuelle recommandée)
- 🛡️ **C++17** avec MinGW ou Visual Studio C++

---

## ⚙️ Compilation

```bash
g++ -std=c++17 -o cryptX *.cpp -mwindows
```

---

## ▶️ Utilisation

```bash
cryptX.exe <chemin_du_fichier_cible>
```

---

## 🧪 Tests

Des tests unitaires sont fournis pour chaque module.

---

## ⚠️ Avertissement

L'utilisation non autorisée de **cryptX** est strictement interdite.

---

## 📝 Licence

📄 Ce projet est sous licence **MIT**. Voir le fichier [LICENSE](LICENSE) pour plus de détails.

---

```markdown
MIT License

© 2025 YoannLetacq

Permission is hereby granted, free of charge, to any person obtaining a copy...
```

---

## 👨‍💻 Auteur

💻 **YoannLetacq** — *cybersecurity student* 🛡️


