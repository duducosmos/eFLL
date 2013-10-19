/*
 * Robotic Research Group (RRG)
 * State University of Piaui (UESPI), Brazil - Piauí - Teresina
 *
 * FuzzyOutput.cpp
 *
 *      Author: Msc. Marvin Lemos <marvinlemos@gmail.com>
 *          Co authors: AJ Alves <aj.alves@zerokol.com>
 *                      Douglas S. Kridi <douglaskridi@gmail.com>
 *                      Kannya Leal <kannyal@hotmail.com>
 */
#include "FuzzyRule.h"

FuzzyRule::FuzzyRule(int index, FuzzyRuleAntecedent* fuzzyRuleAntecedent, FuzzyRuleConsequent* fuzzyRuleConsequent){
	this->index = index;
	this->fuzzyRuleAntecedent = fuzzyRuleAntecedent;
	this->fuzzyRuleConsequent = fuzzyRuleConsequent;
	this->fired = false;
}

int FuzzyRule::getIndex(){
	return this->index;
}

bool FuzzyRule::evaluateExpression(){
	if (this->fuzzyRuleAntecedent != NULL){
		float powerOfAntecedent = this->fuzzyRuleAntecedent->evaluate();

		(powerOfAntecedent > 0.0) ?	(this->fired = true) : (this->fired = false);
		
		this->fuzzyRuleConsequent->evaluate(powerOfAntecedent);
	}
	return this->fired;
}

bool FuzzyRule::isFired(){
	return this->fired;
}