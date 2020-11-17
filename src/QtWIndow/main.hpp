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

class Window : public QWidget {

	Q_OBJECT

	private:
		QTextEdit* monText;
		QVBoxLayout* layout;
		QPushButton* quitter;
		QPushButton* afficher;
		QLabel* label;

	public:
		Window(){
			label = new QLabel(this);
			label->move(500, 500);
			layout = new QVBoxLayout(this);
			setLayout(layout);

			quitter = new QPushButton("Quitter");
			connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

			afficher = new QPushButton("Afficher l'arbre");
			connect(afficher, SIGNAL(clicked()), this, SLOT(afficherArbre()));
			layout->addWidget(label);
			layout->addWidget(afficher);
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
			label->setText(tout);
			//QString ligne;
			// while(! flux.atEnd()){
			// 	ligne = flux.readLine();
			// 	std::cout << ligne.toStdString() << std::endl;
			// 	label->setText(ligne);
			//}
		}

};