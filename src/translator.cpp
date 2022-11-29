/***************************************************************************
 *   Copyright (C) 2006 by Massimiliano Torromeo   *
 *   massimiliano.torromeo@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <fstream>
#include <stdarg.h>

#include "translator.h"
#include "debug.h"

using std::ifstream;

extern string dataPath, homePath;

char tr_buf[512]; 

const char* _F(const char *buf, ...)
{
    // int total, i, temp;
    // total = 0;
    // va_list args;
    // va_start(args, count);
    // for(i=0; i<count; i++)
    // {
    //     temp = va_arg(args, int);
    //     total += temp;
    // }
    // va_end(args);
    // return total;

// void foo(const char *firstArg, ...) {
    va_list argList;
    va_start(argList, buf);

    vsprintf(tr_buf, buf, argList);

    va_end(argList);
// }
	return tr_buf;



}














// Translator::Translator(const string &lang) {
// 	_lang = "";
// 	if (!lang.empty())
// 		setLang(lang);
// }

// Translator::~Translator() {}

// bool Translator::exists(const string &term) {
// 	return translations.find(term) != translations.end();
// }

// void Translator::setLang(const string &lang) {
// 	translations.clear();

// 	string line = dataPath + "/translations/" + lang;
// 	ifstream f(line, std::ios_base::in);
// 	if (f.is_open()) {
// 		while (getline(f, line, '\n')) {
// 			line = trim(line);
// 			if (line.empty() || line[0] == '#') continue;
// 			string::size_type position = line.find("=");
// 			translations[trim(line.substr(0, position))] = trim(line.substr(position + 1));
// 		}
// 		f.close();
// 		_lang = lang;
// 	}
// }

// string Translator::translate(const string &term,const char *replacestr,...) {
// 	string result = term;

// 	if (!_lang.empty()) {
// 		unordered_map<string, string>::iterator i = translations.find(term);
// 		if (i != translations.end()) {
// 			result = i->second;
// 		}
// 		//else WARNING("Untranslated string: '%s'", term.c_str());
// 	}

// 	va_list arglist;
// 	va_start(arglist, replacestr);
// 	const char *param = replacestr;
// 	int argnum = 1;
// 	while (param!=NULL) {
// 		string id = "";
// 		stringstream ss; ss << argnum; ss >> id;
// 		result = strreplace(result, "$" + id, param);

// 		param = va_arg(arglist, const char*);
// 		argnum++;
// 	}
// 	va_end(arglist);

// 	return result;
// }

// string Translator::operator[](const string &term) {
// 	return translate(term);
// }

// string Translator::lang() {
// 	return _lang;
// }
