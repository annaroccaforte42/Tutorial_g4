#include "action.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}
void MyActionInitialization::Build() const
{
    G4cout<<"MyActionInitialization::Build()"<<G4endl;
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
    G4cout<<"MyActionInitialization::Build()::end"<<G4endl;
}
