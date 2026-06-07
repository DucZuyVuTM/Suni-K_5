#include "Suni_app.h"

int main() {
	Suni_app shl_thucthi(nullptr);      // создание корневого объекта
	shl_thucthi.Taoj_cay_phan_cap();    // конструирование системы, построение дерева объектов
	return shl_thucthi.pearnet_tong();  // запуск системы
}
