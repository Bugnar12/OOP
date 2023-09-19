#include "Domain.h"
#include "Repository.h"
#include "Services.h"
#include "Tests.h"
#include "UI.h"
#include "DynamicArray.h"
#include <stdio.h>
#include "Operations.h"

int main()
///Main function of the program
{
//    Repository* repository = createRepository();
//    OperationStack* undoStack = createStack();
//    OperationStack* redoStack = createStack();
//    Service* service = createService(repository, undoStack, redoStack);

      testDomain();

      testDynamicArray();

      testRepository();

      testOperations();

      testService();

      testValidator();

//       UI* ui = createUI(service);
//
//       run(ui);
//
//    destroyRepository(repository);
//    destroyStack(undoStack);
//    destroyStack(redoStack);
//    destroyService(service);
// //   destroyUI(ui);
}
