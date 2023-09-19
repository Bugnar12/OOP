#ifndef A23_V2_UI_H
#define A23_V2_UI_H

#include "Services.h"

typedef struct {
    Service *service;
}UI;

UI* createUI(Service* s);
void destroyUI(UI* ui);

void run(UI *ui);

void printings();

void addEstateUI(UI* ui);

void deleteEstateUI(UI* ui);

void updateEstateUI(UI* ui);

void displayEstates(UI* ui);

void SortByPriceUI(UI* ui);

void filterBySurfaceUI(UI* ui);

void returning(UI* ui);

#endif //A23_V2_UI_H
