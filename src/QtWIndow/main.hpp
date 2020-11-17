#pragma once

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QPainter>
#include <QTextStream>
#include <QFile>
#include <QTextEdit> 
#include <QLabel>
#include <QColor>


class Window : public QWidget {

	Q_OBJECT

	private:
		QTextEdit* monText;
		QVBoxLayout* layout;
		QPushButton* quitter;
		QPushButton* afficher;
		QPushButton* supprimer;
		QTextEdit* zoneTexte;

	public:
		Window(){

			setWindowTitle("Binary Tree");

			zoneTexte = new QTextEdit(this);
			zoneTexte->setTextColor(Qt::green);
			zoneTexte->setFontWeight(QFont::Black);
			//zoneTexte->setFontFamily("Yrsa Bold");
			zoneTexte->setFontPointSize(20);
			zoneTexte->setReadOnly(true);

			layout = new QVBoxLayout(this);
			setLayout(layout);

			quitter = new QPushButton("Quitter");
			connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

			afficher = new QPushButton("Afficher l'arbre");
			connect(afficher, SIGNAL(clicked()), this, SLOT(afficherArbre()));

			supprimer = new QPushButton("Supprimer l'arbre");
			connect(supprimer, SIGNAL(clicked()), this, SLOT(supprimerArbre()));

			layout->addWidget(zoneTexte);
			layout->addWidget(afficher);
			layout->addWidget(supprimer);
			layout->addWidget(quitter);

		}

		~Window(){

		}

	public slots:
		void afficherArbre(){
			
			QString fileName = "binary.txt";
			QFile fichier(fileName);
			fichier.open(QIODevice::ReadOnly | QIODevice::Text);
			QTextStream flux(&fichier);

			QString tout = flux.readAll();
			zoneTexte->setText(tout);
			resize(1000,1000);
			zoneTexte->show();
		}

		void supprimerArbre(){
			zoneTexte->setText(nullptr);
			resize(200, 200);
			zoneTexte->show();
		}

};