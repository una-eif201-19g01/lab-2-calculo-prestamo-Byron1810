//
// Created by Byron Argüello Rodríguez on 2019-08-12.
//

#include <iostream>
#include "CalculoPrestamo.h"

CalculoPrestamo::CalculoPrestamo(){}

CalculoPrestamo::CalculoPrestamo(int64_t monto) : monto(monto){}

float CalculoPrestamo::getMonto(){
	return monto;
}

void CalculoPrestamo::setMonto(float monto){
	CalculoPrestamo::monto = monto;
}

float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT)
{
    float porcentaje= 0;
	int buscarPorcentaje = porcentajeTXT.find("%");
	
	if (buscarPorcentaje >0){
		porcentaje = std::stof(porcentajeTXT.substr(0, buscarPorcentaje));
		if (porcentaje > 0){
			porcentaje = porcentaje / 100;
		}
	}
	return porcentaje;
}

int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTxT)
{
    int meses= 0;
	int annio = 0;
	int buscarTiempoAnnio = tiempoTxT.find("A");
	int buscarTiempoMes = tiempoTxT.find("M");
	
	if (buscarTiempoAnnio > 0) {
		annio = stoi(tiempoTxT.substr(0, buscarTiempoAnnio));
		if (annio > 0) {
			meses = annio * 12;
		}
	} else if (buscarTiempoMes > 0) {
		meses = stoi(tiempoTxT.substr(0, buscarTiempoMes));
	}
	return meses;
}

float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual) {
	float tasaMensual = tasaAnual / 12;
	float interes = tasaMensual * balance;
	return interes;
}

std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTxT, std::string porcentajeTxT) {
	std::string reporte = "";
	int meses = calcularTiempoEnMeses(tiempoTxT) + 1;
	float porcentaje = obtenerPorcentaje(porcentajeTxT);
	float balance = getMonto();
	float balanceNuevo = getMonto();

	for (int mes = 1; mes < meses; ++mes) {
		float interesMensual = calcularInteresMensual(balanceNuevo, porcentaje);
		balance = balanceNuevo;
		balanceNuevo = balance + interesMensual;

		reporte = reporte + "Tasa [" + porcentajeTxT + "], Mes [" + std::to_string(mes) + "], balance inicial[" + std::to_string(balance) + 
			    "], interes [" + std::to_string(interesMensual) + "], balance nuevo [" + std::to_string(balanceNuevo) + "] \n";
	}
	return reporte;
}