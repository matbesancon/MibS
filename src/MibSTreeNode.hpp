/*===========================================================================*/
/* This file is part of a Mixed Integer Bilevel Solver                       */
/* developed using the BiCePS Linear Integer Solver (BLIS).                  */
/*                                                                           */
/* Authors: Scott DeNegre, Lehigh University                                 */
/*          Ted Ralphs, Lehigh University                                    */
/*                                                                           */
/* Copyright (C) 2007-2015 Lehigh University, Scott DeNegre, and Ted Ralphs. */
/* All Rights Reserved.                                                      */
/*                                                                           */
/* This software is licensed under the Eclipse Public License. Please see    */
/* accompanying file for terms.                                              */
/*===========================================================================*/

#ifndef MibSTreeNode_h_
#define MibSTreeNode_h_

#include "Alps.h"
#include "AlpsEncoded.h"

#include "BlisTreeNode.h"

//#############################################################################

class MibSTreeNode : public BlisTreeNode {

 private:
   
  double lowerUpperBound_;
  bool boundSet_;
  
 public:
  
  MibSTreeNode();
  MibSTreeNode(AlpsNodeDesc *&desc);
  MibSTreeNode(BlisModel *m);

  ~MibSTreeNode();
  
  void setIsBoundSet(bool val) {boundSet_ = val;}
  void setLowerUB(double bound) {lowerUpperBound_ = bound;}
  inline bool isBoundSet() {return boundSet_;}
  inline double getLowerUB() {return lowerUpperBound_;}
  AlpsTreeNode* createNewTreeNode(AlpsNodeDesc *&desc) const;
  int process(bool isRoot, bool rampUp);
};

#endif