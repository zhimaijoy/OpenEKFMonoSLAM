//Copyright (C) 2013 Sergio E. Gonzalez and Emiliano D. González
//Facultad de Ciencias Exactas y Naturales, Universidad de Buenos Aires, Buenos Aires, Argentina.
// 
//C/C++, Java and XML/YML code for EKF SLAM from a monocular sequence.
//
//This file is part of OpenEKFMonoSLAM.
//
//OpenEKFMonoSLAM is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//OpenEKFMonoSLAM is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with OpenEKFMonoSLAM.  If not, see <http:www.gnu.org/licenses/>.
//
//If you use this code for academic work, please reference:
//GONZALEZ, S.; E. GONZÁLEZ; M. NITSCHE; P. DE CRISTÓFORIS. "Odometría Visual para Robots Móviles Utilizando Smartphones como Unidad de Sensado y Procesamiento". En: Jornadas Argentinas de Robótica, 8as : 2014 : Ciudad Autónoma de Buenos Aires. Actas : VIII Jornadas Argentinas de Robótica . (8 : Ciudad Autónoma de Buenos Aires, 12-14 de noviembre 2014).
//
//Authors:    Sergio E. Gonzalez - segonzalez@dc.uba.ar
//            Emiliano D. González - edgonzalez@dc.uba.ar
//
//Departamento de Computación
//Facultad de Ciencias Exactas y Naturales
//Universidad de Buenos, Buenos Aires, Argentina
//Date: June 2013

#include "Points1d.h"

Points1d::Points1d(){}

Points1d::~Points1d(){}

void Points1d::add(int x)
{
    _data.push_back(x);
}

void Points1d::save(std::string dirname, std::string filename)
{
    std::ofstream f;
    std::string file = dirname + filename + ".m";
    f.open(file.c_str());

    // Se guardan los datos en formato matlab

    f << "function x = " << filename << "()" << std::endl;

    // Datos
    saveVector(f, "x", _data);

    f << "end";

    f.close();
}

void Points1d::saveVector(std::ofstream &f, std::string matlabVar, std::vector<int> &v)
{
    int size = v.size();
    f << matlabVar << " = [";

    if (size > 1)
    {
        f << v[0];
        saveFrom(f, 1, v);
    }
    else if (size  == 1)
    {
        f << v[0];
    }
    f << "];" << std::endl;
}

void Points1d::saveFrom(std::ofstream &f, int init, std::vector<int> &v)
{
    for (unsigned int i = init; i < v.size(); ++i)
    {
        f << ", " << v[i];
    }
}
