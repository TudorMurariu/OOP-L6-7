#pragma once
#include "Repo.h"

class Repo;

class Undo {
public:
	//friend class Repo;
	virtual void undo() = 0;
	virtual ~Undo() = default;
};


class Undo_Add : public Undo {

public:
	Repo& repo;
	Undo_Add(Repo& Rep) : repo(Rep) {}
	void undo() override {
		repo.Delete_Last();
	}
};

//class Undo_Delete : public Undo {
//
//private:
//	Repo& repo;
//	Oferta x;
//
//public:
//	Undo_Delete(Repo& Rep, Oferta oferta) : repo(Rep) , x(oferta) {}
//	void undo() override  {
//		repo.Add(x);
//	}
//};
//
//class Undo_Modify : public Undo {
//private:
//	Repo& repo;
//	Oferta x;
//public:
//	Undo_Modify(Repo& Rep, Oferta oferta) : repo(Rep), x(oferta) {}
//	void undo() override  {
//		repo.Modificare(x);
//	}
//};