/*
 * Transportadora.cpp
 *
 *  Created on: 22/02/2015
 *      Author: Mizael Martinez
 */
#include<iostream>
#include"rapidjson/document.h"
#include"arduino.h"
using namespace rapidjson;
class ParsearJson{
	private:
		const char *json;
		Document documento;
	public:
		ParsearJson(const char *json);
		Transportadora convertirJsonAObjeto(Transportadora configuracion);
};
ParsearJson::ParsearJson(const char *json)
{
	this->json=json;
	this->documento.Parse(json);
	printf("\n%.2f\n",this->documento["uno"].GetDouble());
	printf("%s---",this->json);
}
Transportadora ParsearJson::convertirJsonAObjeto(Transportadora configuracion)
{
	configuracion.establecerTemperaturaMin(this->documento["temperatura_min"].GetDouble());
	configuracion.establecerTemperaturaMax(this->documento["temperatura_max"].GetDouble());
	configuracion.establecerHumedadMin(this->documento["humedad_min"].GetDouble());
	configuracion.establecerHumedadMax(this->documento["humedad_max"].GetDouble());
	configuracion.establecerLatitudInicio(this->documento["latitud_inicio"].GetDouble());
	configuracion.establecerLongitudInicio(this->documento["longitud_inicio"].GetDouble());
	configuracion.establecerLatitudFinal(this->documento["latitud_final"].GetDouble());
	configuracion.establecerLongitudFinal(this->documento["longitud_final"].GetDouble());
	const Value& telefonos=this->documento["telefonos"];
	int arregloTelefonos[telefonos.Size()];
	for(SizeType i=0;i<telefonos.Size();i++)
	{
		arregloTelefonos[i]=telefonos[i].GetInt();
	}
	configuracion.establecerTelefonos(arregloTelefonos,telefonos.Size());
	return configuracion;
}
int main(int argc,char *argv[])
{

    return 0;
}
