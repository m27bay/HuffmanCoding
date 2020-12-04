/**
 * Writer.hpp : You can found here the Writer class.
 * Author : Mickael.
 **/

#ifndef Writer_HPP
#define Writer_HPP

#include "Tree.hpp"
#include "Parser.hpp"
#include <fstream>
#include <map>
#include "../test/Test.hpp"

class Writer
{
	private:
		/* Data */
		std::string file; // The name of the file

	public:
		/* Constructor */
		Writer();
		Writer(std::string);

		/* Methodes */
		void writeBeautifulTreeInFile(ArbreB);
		void writeBeautifulTreeInFileRec(Sommet*, int, std::ofstream&);
		void writeResultAllTests();
		void textToCode(std::string);
};

#endif