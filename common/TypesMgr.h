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

#pragma once

#include <vector>
#include <string>
#include <iostream>

#include <cstddef>    // std::size_t

// using namespace std;


////////////////////////////////////////////////////////////////
// Class TypesMgr: creates and stores types, and give access
// to type information.
// When a type is created the TypesMgr returns its TypeId.
// The TypeId is the public way to work with types.
// This TypeMgr works with five kinds of primitive types:
// integer, float, boolean, character and void. Also it
// recognizes two compound types: functions and fixed-size
// arrays. Finally there exist a special type 'error'.

class TypesMgr {

public:

  // The TypeId is an index in a vector
  typedef std::size_t TypeId;

  // Constructor
  TypesMgr ();

  // Methods to create a Type and return its TypeId
  //   - Primitive and error types
  TypeId createErrorTy     ();
  TypeId createIntegerTy   ();
  TypeId createFloatTy     ();
  TypeId createBooleanTy   ();
  TypeId createCharacterTy ();
  TypeId createVoidTy      ();
  //   - Compound types
  TypeId createFunctionTy  (const std::vector<TypeId> & paramsTypes,
			    TypeId                      returnType);
  TypeId createArrayTy     (unsigned int                size,
		            TypeId                      elemType);

  // Accessors to work with primitive and error types
  bool isErrorTy            (TypeId tid) const;
  bool isIntegerTy          (TypeId tid) const;
  bool isFloatTy            (TypeId tid) const;
  bool isBooleanTy          (TypeId tid) const;
  bool isCharacterTy        (TypeId tid) const;
  bool isVoidTy             (TypeId tid) const;
  bool isNumericTy          (TypeId tid) const;
  bool isPrimitiveTy        (TypeId tid) const;
  bool isPrimitiveNonVoidTy (TypeId tid) const;

  // Accessors to work with function types
  bool                        isFunctionTy       (TypeId tid)     const;
  const std::vector<TypeId> & getFuncParamsTypes (TypeId tid)     const;
  TypeId                      getFuncReturnType  (TypeId tid)     const;
  std::size_t                 getNumOfParameters (TypeId tid)     const;
  TypeId                      getParameterType   (TypeId tid,
					          unsigned int i) const;
  bool                        isVoidFunction     (TypeId tid)     const;

  // Accessors to work with array types
  bool         isArrayTy        (TypeId tid) const;
  unsigned int getArraySize     (TypeId tid) const;
  TypeId       getArrayElemType (TypeId tid) const;

  // Methods to check different compatibilities of types
  //   - structurally equal?
  bool equalTypes      (TypeId tid1, TypeId tid2)     const;
  //   - comparable with the relational operator op?
  bool comparableTypes (TypeId tid1, TypeId tid2,
			const std::string & op)       const;
  //   - tidFrom values can be copied to tidTo?
  bool copyableTypes   (TypeId tidTo, TypeId tidFrom) const;

  // Method to compute the size of a type (primitive type size = 1)
  std::size_t getSizeOfType (TypeId tid) const;

  // Methods to convert to string and print types
  std::string to_string (TypeId         tid)            const;
  void        dump      (TypeId         tid,
		         std::ostream & os = std::cout) const;


private:
  // Forward declaration of class Type
  class Type;

  // Attributes:
  //   - vector to save the Types
  std::vector<Type> TypesVec;

  // There are eight kinds of types:
  //   - an especial kind error,
  //   - five primitive kinds: integer, float, boolean, character and void
  //   - two compound kinds: function and array
  enum TypeKind {
    FirstPrimitiveKind = -1,
    // Primitive/fundamental data types ("error" type is included):
    ErrorKind          = 0,  // "error" type. MUST BE THE FIRST AND MUST BE ZERO
    IntegerKind        ,     // integer type
    FloatKind          ,     // floating point type
    BooleanKind        ,     // boolean type
    CharacterKind      ,     // char type
    VoidKind           ,     // void type with no size
    LastPrimitiveKind  ,
    // Compound data types:
    FunctionKind       ,     // function types
    ArrayKind          ,     // array types
  };

  // Static attributes:
  //   - the TypeId of ALL the integers created (IntegerTyId) will be
  //     the same (and it is equal to TypeKind::IntegerKind).
  //     Exactly the same for the rest of primitive and error types.
  static const TypeId ErrorTyId     = TypeKind::ErrorKind;
  static const TypeId IntegerTyId   = TypeKind::IntegerKind;
  static const TypeId FloatTyId     = TypeKind::FloatKind;
  static const TypeId BooleanTyId   = TypeKind::BooleanKind;
  static const TypeId CharacterTyId = TypeKind::CharacterKind;
  static const TypeId VoidTyId      = TypeKind::VoidKind;

  //   - number of primitive and 'error' types
  static const unsigned int NumPrimitiveAndErrorTypes = LastPrimitiveKind - FirstPrimitiveKind - 1;


  //////////////////////////////////////////////////////////////////
  // Class Type: is declared inside TypeMgr and is private,
  // so only the TypeMgr can operate with Type objects.
  // It keeps the information of any type. When a type is
  // compound, the subtypes (for example the types of the parameters
  // of a function, or the type of the elements of an array) are
  // referenced by their respective TypeId's.
  class Type {

  public:
    // Constructors for primitive, function and array Types
    Type (TypeKind                    tid = TypeKind::VoidKind);
    Type (const std::vector<TypeId> & paramsTypes,
	  TypeId                      returnType);
    Type (unsigned int                arraySize,
	  TypeId                      arrayElemType);

    // Destructor
    ~Type () = default;

    // Accesor to get the kind
    TypeKind getTypeKind () const;

    // Accessors to work with primitive and 'error' types
    bool isErrorTy            () const;
    bool isIntegerTy          () const;
    bool isFloatTy            () const;
    bool isBooleanTy          () const;
    bool isCharacterTy        () const;
    bool isVoidTy             () const;
    bool isNumericTy          () const;
    bool isPrimitiveTy        () const;
    bool isPrimitiveNonVoidTy () const;

    // Accessors to work with function types
    bool                        isFunctionTy       ()               const;
    const std::vector<TypeId> & getFuncParamsTypes ()               const;
    TypeId                      getFuncReturnType  ()               const;
    std::size_t                 getNumOfParameters ()               const;
    TypeId                      getParameterType   (unsigned int i) const;
    bool                        isVoidFunction     ()               const;

    // Accessors to work with array types
    bool         isArrayTy        () const;
    unsigned int getArraySize     () const;
    TypeId       getArrayElemType () const;

  private:

    // Atributes:
    //   - the kind of type
    TypeKind ID;
    //   - to represent the type of a function:
    std::vector<TypeId> funcParamsTy;
    TypeId funcReturnTy;
    //   - to represent the type of an array:
    unsigned int arraySize;
    TypeId arrayElemTy;

  };  // class Type

};  // class TypesMgr
