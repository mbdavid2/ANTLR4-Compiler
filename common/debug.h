//////////////////////////////////////////////////////////////////////
//
//    debug - define some optional macros useful in debugging
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
//////////////////////////////////////////////////////////////////////

#pragma once

#include "antlr4-runtime.h"

#include <iostream>
#include <string>

// using namespace std;


//////////////////////////////////////////////////////////////////////
// This file contains 3 DEBUG macros to be used in the listeners:
//   DEBUG(x)          : with a 'message' x (to use anywhere):
//                       DEBUG("x:" << x << " y:" << y);
//   DEBUG_ENTER()     : for the enter message in a rule method, and
//   DEBUG_EXIT()      : for the exit message in a rule method
//
// These messages can be enabled in a specific module/listener
// defining the variable DEBUG_BUILD *before* the inclusion
// of this file

#ifdef DEBUG_BUILD
  #define DEBUG(x) do { std::cout << x << std::endl; } while (0)
  #define DEBUG_ENTER() DEBUG(">>> enter " << std::string(__func__).substr(5) << " [source pos " << ctx->getStart()->getLine() << ":" << ctx->getStart()->getCharPositionInLine() << "] [module: " << std::string(typeid(*this).name()).substr(2,std::string(typeid(*this).name()).find("Listener")-2) << "]")
  #define DEBUG_EXIT() DEBUG(">>> exit " << std::string(__func__).substr(4) << " [source pos " << ctx->getStart()->getLine() << ":" << ctx->getStart()->getCharPositionInLine() << "] [module: " << std::string(typeid(*this).name()).substr(2,std::string(typeid(*this).name()).find("Listener")-2) << "]")
#else
  #define DEBUG(x)
  #define DEBUG_ENTER()
  #define DEBUG_EXIT()
#endif
