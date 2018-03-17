/////////////////////////////////////////////////////////////////
//
//    TypesMgr - Type System for the Asl programming language
//
//    Copyright (C) 2018  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
////////////////////////////////////////////////////////////////


#include "TypesMgr.h"

#include <vector>
#include <string>
#include <iostream>

#include <cstddef>    // std::size_t
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// using namespace std;


// ======================================================================
// class TypesMgr

// ----------------------------------------------------------------------
// constructor

TypesMgr::TypesMgr() {
  // Prebuilt and insert in TypesVec the Type's of the primitive types
  TypesVec = std::vector<Type>(NumPrimitiveAndErrorTypes);
  TypesVec[ErrorTyId]     = Type(TypeKind::ErrorKind);
  TypesVec[IntegerTyId]   = Type(TypeKind::IntegerKind);
  TypesVec[FloatTyId]     = Type(TypeKind::FloatKind);
  TypesVec[BooleanTyId]   = Type(TypeKind::BooleanKind);
  TypesVec[CharacterTyId] = Type(TypeKind::CharacterKind);
  TypesVec[VoidTyId]      = Type(TypeKind::VoidKind);
}

// ----------------------------------------------------------------------
// methods to create a Type and return its TypeId

TypesMgr::TypeId TypesMgr::createErrorTy() {
  return ErrorTyId;
}

TypesMgr::TypeId TypesMgr::createIntegerTy() {
  return IntegerTyId;
}

TypesMgr::TypeId TypesMgr::createFloatTy() {
  return FloatTyId;
}

TypesMgr::TypeId TypesMgr::createBooleanTy() {
  return BooleanTyId;
}

TypesMgr::TypeId TypesMgr::createCharacterTy() {
  return CharacterTyId;
}

TypesMgr::TypeId TypesMgr::createVoidTy() {
  return VoidTyId;
}

TypesMgr::TypeId TypesMgr::createFunctionTy(const std::vector<TypeId> & paramsTypes,
					    TypeId returnType) {
  TypesVec.push_back(Type(paramsTypes, returnType));
  return TypesVec.size()-1;
}

TypesMgr::TypeId TypesMgr::createArrayTy(unsigned int size,
					 TypeId elemType) {
  TypesVec.push_back(Type{size, elemType});
  return TypesVec.size()-1;
}

// ----------------------------------------------------------------------
// accessors for working with primitive types

bool TypesMgr::isErrorTy(TypeId tid) const {
  return tid == ErrorTyId;
}

bool TypesMgr::isIntegerTy(TypeId tid) const {
  return tid == IntegerTyId;
}

bool TypesMgr::isFloatTy(TypeId tid) const {
  return tid == FloatTyId;
}

bool TypesMgr::isBooleanTy(TypeId tid) const {
  return tid == BooleanTyId;
}

bool TypesMgr::isCharacterTy(TypeId tid) const {
  return tid == CharacterTyId;
}

bool TypesMgr::isVoidTy(TypeId tid) const {
  return tid == VoidTyId;
}

bool TypesMgr::isNumericTy(TypeId tid) const {
  return (tid == IntegerTyId or tid == FloatTyId);
}

bool TypesMgr::isPrimitiveTy(TypeId tid) const {
  return (tid == IntegerTyId or tid == FloatTyId or
	  tid == BooleanTyId or tid == CharacterTyId or
	  tid == VoidTyId);
}

bool TypesMgr::isPrimitiveNonVoidTy(TypeId tid) const {
  return (isPrimitiveTy(tid) and not isVoidTy(tid));
}

// ----------------------------------------------------------------------
// accessors for working with function types

bool TypesMgr::isFunctionTy(TypeId tid) const {
  const Type & t = TypesVec.at(tid);
  return t.isFunctionTy();
}

const std::vector<TypesMgr::TypeId> & TypesMgr::getFuncParamsTypes(TypeId tid) const {
  const Type & t = TypesVec.at(tid);
  assert(t.isFunctionTy());
  return t.getFuncParamsTypes();
}

TypesMgr::TypeId TypesMgr::getFuncReturnType(TypeId tid) const {
  const Type & t = TypesVec.at(tid);
  assert(t.isFunctionTy());
  return t.getFuncReturnType();
}

std::size_t TypesMgr::getNumOfParameters(TypeId tid) const {
  const Type & t = TypesVec.at(tid);
  assert(t.isFunctionTy());
  return t.getNumOfParameters();
}

TypesMgr::TypeId TypesMgr::getParameterType(TypeId tid, unsigned int i) const {
  const Type & t = TypesVec.at(tid);
  assert(t.isFunctionTy() and i < t.getNumOfParameters());
  return t.getParameterType(i);
}

bool TypesMgr::isVoidFunction(TypeId tid) const {
  const Type & t = TypesVec.at(tid);
  assert(t.isFunctionTy());
  TypeId tr = t.getFuncReturnType();
  return isVoidTy(tr);
}

// ----------------------------------------------------------------------
// accessors for working with array types

bool TypesMgr::isArrayTy(TypeId tid) const {
  const Type & t = TypesVec.at(tid);
  return t.isArrayTy();
}

unsigned int TypesMgr::getArraySize(TypeId tid) const {
  const Type & t = TypesVec.at(tid);
  assert(t.isArrayTy());
  return t.getArraySize();
}

TypesMgr::TypeId TypesMgr::getArrayElemType(TypeId tid) const {
  const Type & t = TypesVec.at(tid);
  assert(t.isArrayTy());
  return t.getArrayElemType();
}

// ----------------------------------------------------------------------
// methods for checking different compatibilities of Types

bool TypesMgr::equalTypes(TypeId tid1, TypeId tid2) const {
  if (tid1 == tid2)
    return true;
  const Type & t1 = TypesVec.at(tid1);
  const Type & t2 = TypesVec.at(tid2);
  if (t1.getTypeKind() != t2.getTypeKind())
    return false;
  if (t1.isPrimitiveTy() and t2.isPrimitiveTy())
    return true;
  if (t1.isFunctionTy()) {  // or: if (t2.isFunctionTy()) {
    if (t1.getNumOfParameters() != t2.getNumOfParameters())
      return false;
    TypeId tid1_aux;
    TypeId tid2_aux;
    for (unsigned int i = 0; i < t1.getNumOfParameters(); ++i) {
      tid1_aux = t1.getParameterType(i);
      tid2_aux = t2.getParameterType(i);
      if (not equalTypes(tid1_aux, tid2_aux))
	return false;
    }
    tid1_aux = t1.getFuncReturnType();
    tid2_aux = t2.getFuncReturnType();
    return equalTypes(tid1_aux, tid2_aux);
  }
  if (t1.isArrayTy()) {  // or: if (t2.isArrayTy()) {
    if (t1.getArraySize() != t2.getArraySize()) {
      return false;
    }
    TypeId tid1_aux = t1.getArrayElemType();
    TypeId tid2_aux = t2.getArrayElemType();
    return equalTypes(tid1_aux, tid2_aux);
  }
  return false;
}

bool TypesMgr::comparableTypes(TypeId tid1, TypeId tid2,
			       const std::string & op) const {
  if ((not isPrimitiveTy(tid1)) or (not isPrimitiveTy(tid2)))
    return false;
  if (isNumericTy(tid1) and isNumericTy(tid2))
    return true;
  if (isCharacterTy(tid1) and isCharacterTy(tid2))
    return true;
  if (isBooleanTy(tid1) and isBooleanTy(tid2) and
      (op == "==" or op == "!="))
    return true;
  return false;
}

bool TypesMgr::copyableTypes(TypeId tid1, TypeId tid2) const {
  if (equalTypes(tid1, tid2))
    return true;
  if (isFloatTy(tid1) and isIntegerTy(tid2))
    return true;
  return false;
}

// ----------------------------------------------------------------------
// method to compute the size of a type (primitive type size = 1)
std::size_t TypesMgr::getSizeOfType (TypeId tid) const {
  if (isPrimitiveNonVoidTy(tid)) return 1;
  if (isArrayTy(tid)) {
    const Type & tArr = TypesVec.at(tid);
    std::size_t nElems = tArr.getArraySize();
    TypeId tElem = tArr.getArrayElemType();
    return nElems * getSizeOfType(tElem);
  }
  return 0;
}

// ----------------------------------------------------------------------
// methods to convert to string and print types

std::string TypesMgr::to_string(TypeId tid) const {
  if (isPrimitiveTy(tid) or isErrorTy(tid)) {
    switch (tid) {
    case ErrorTyId:     return "error";
    case IntegerTyId:   return "integer";
    case FloatTyId:     return "float";
    case BooleanTyId:   return "boolean";
    case CharacterTyId: return "character";
    case VoidTyId:      return "void";
    }
  }
  const Type & t = TypesVec.at(tid);
  if (t.isFunctionTy()) {
    TypeId tid1;
    std::string s = "function<";
    if (t.getNumOfParameters() > 0) {
      tid1 = t.getParameterType(0);
      s = s + to_string(tid1);
    }
    for (unsigned int i = 1; i < t.getNumOfParameters(); ++i) {
      tid1 = t.getParameterType(i);
      s = s + "," + to_string(tid1);
    }
    tid1 = t.getFuncReturnType();
    s = s + ">:" + to_string(tid1);
    return s;
  }
  else if (t.isArrayTy()) {
    TypeId tid1;
    std::string s = "array<" + std::to_string(t.getArraySize()) + ",";
    tid1 = t.getArrayElemType();
    s = s + to_string(tid1) +">";
    return s;
  }
  else {
    return "none";
  }
}

void TypesMgr::dump(TypeId tid, std::ostream & os) const {
  os << to_string(tid);
}


// ======================================================================
// class TypesMgr::Type

// ----------------------------------------------------------------------
// constructors

TypesMgr::Type::Type(TypeKind tid) : ID{tid} {
  assert(TypeKind::FirstPrimitiveKind < ID and
	 ID < TypeKind::LastPrimitiveKind);
}

TypesMgr::Type::Type(const std::vector<TypeId> & paramsTypes, TypeId returnType) :
  ID{TypesMgr::TypeKind::FunctionKind},
  funcParamsTy{paramsTypes},
  funcReturnTy{returnType} {
  }

TypesMgr::Type::Type(unsigned int arraySize, TypeId arrayElemType) :
  ID{TypesMgr::TypeKind::ArrayKind},
  arraySize{arraySize},
  arrayElemTy{arrayElemType} {
  }

// ----------------------------------------------------------------------
// accesor to get the kind

TypesMgr::TypeKind TypesMgr::Type::getTypeKind () const {
  return ID;
}

// ----------------------------------------------------------------------
// accessors for working with primitive types

bool TypesMgr::Type::isErrorTy() const {
  return ID == TypeKind::ErrorKind;
}

bool TypesMgr::Type::isIntegerTy() const {
  return ID == TypeKind::IntegerKind;
}

bool TypesMgr::Type::isFloatTy() const {
  return ID == TypeKind::FloatKind;
}

bool TypesMgr::Type::isBooleanTy() const {
  return ID == TypeKind::BooleanKind;
}

bool TypesMgr::Type::isCharacterTy() const {
  return ID == TypeKind::CharacterKind;
}

bool TypesMgr::Type::isVoidTy() const {
  return ID == TypeKind::VoidKind;
}

bool TypesMgr::Type::isNumericTy() const {
  return (ID == TypeKind::IntegerKind or
	  ID == TypeKind::FloatKind);
}

bool TypesMgr::Type::isPrimitiveTy() const {
  return (ID == TypeKind::IntegerKind or
	  ID == TypeKind::FloatKind or
	  ID == TypeKind::BooleanKind or
	  ID == TypeKind::CharacterKind or
	  ID == TypeKind::VoidKind);
}

bool TypesMgr::Type::isPrimitiveNonVoidTy() const {
  return (isPrimitiveTy() and not isVoidTy());
}

// ----------------------------------------------------------------------
// accessors for working with function types

bool TypesMgr::Type::isFunctionTy() const {
  return ID == TypeKind::FunctionKind;
}

const std::vector<TypesMgr::TypeId> & TypesMgr::Type::getFuncParamsTypes() const {
  return funcParamsTy;
}

TypesMgr::TypeId TypesMgr::Type::getFuncReturnType() const {
  return funcReturnTy;
}

std::size_t TypesMgr::Type::getNumOfParameters() const {
  return getFuncParamsTypes().size();
}

TypesMgr::TypeId TypesMgr::Type::getParameterType(unsigned int i) const {
  assert(i < getNumOfParameters());
  return getFuncParamsTypes()[i];
}

bool TypesMgr::Type::isVoidFunction() const {
  return getFuncReturnType() == TypeKind::VoidKind;
}

// ----------------------------------------------------------------------
// accessors for working with array types

bool TypesMgr::Type::isArrayTy() const {
  return ID == TypeKind::ArrayKind;
}

unsigned int TypesMgr::Type::getArraySize() const {
  return arraySize;
}

TypesMgr::TypeId TypesMgr::Type::getArrayElemType() const {
  return arrayElemTy;
}
