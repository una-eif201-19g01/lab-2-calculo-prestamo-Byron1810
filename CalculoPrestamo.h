//
// Created by Byron Argüello Rodríguez on 2019-08-12.
//

#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <cstdint>
#include <string>

class CalculoPrestamo {

private:
	float monto;
	float obtenerPorcentaje(std::string porcentajeTxT);
	int calcularTiempoEnMeses(std::string tiempoTxT);
	float calcularInteresMensual(float balance, float tasaAnual);

public:
	CalculoPrestamo();
	CalculoPrestamo(int64_t monto);
	std::string reporteCalculoPrestamo(std::string tiempoTxT, std::string porcentajeTxT);
	float getMonto();
	void setMonto(float monto);
};

#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
