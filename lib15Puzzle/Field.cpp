#include "Field.h"
#include <iostream>
#include <exception>
#include <random>
using namespace Puzzle15;


//�l���Z�b�g : ���̒l�����e
Block::Block(int num)
:_num(num)
{
}

Block::~Block()
{
}

const int Block::num() const
{
	return _num;
}

const bool Block::operator==(const Block& rhs) const
{
	return (this->num() == rhs.num());
}

//*************************************************************************

Field::Field()
{
	Initialize();
}


Field::~Field()
{
}

void Field::Initialize()
{
	for (int i = 0; i < _blocks.size()-1; i++){
		_blocks[i] = std::unique_ptr<Block>(new Block(i+1));
	}
	_blankPosision = FIELD_W * FIELD_H - 1;
	_blocks[_blankPosision] = nullptr;
}

const std::unique_ptr<Block>& Field::operator[](int index) const
{
	return this->at(index);
}

const std::unique_ptr<Block>& Field::at(int index) const
{
	if (index < 0 || index >= FIELD_H*FIELD_W){
		throw std::out_of_range("Error : Field::operator[]�̑�1����(index)���͈͊O�ł��B");
	}
	return _blocks[index];
}


void Field::Swap(int idx1, int idx2)
{
	if (idx1 < 0 || idx1 >= FIELD_H*FIELD_W){
		throw std::out_of_range("Error : Field::Swap�̑�1����(idx1)���͈͊O�ł��B");
	}
	else if (idx2 < 0 || idx2 >= FIELD_H*FIELD_W){
		throw std::out_of_range("Error : Field::Swap�̑�2����(idx2)���͈͊O�ł��B");
	}

	std::swap(_blocks[idx1], _blocks[idx2]);

	if (idx1 == _blankPosision){
		_blankPosision = idx2;
		return;
	}
	if (idx2 == _blankPosision){
		_blankPosision = idx1;
		return;
	}

	
}

bool Field::CheckComplete() const
{
	//�Ōォ��2�ڂ̗v�f�܂ł����ɕ���ł��邩���ׂ�
	//�r���ɋ�̗v�f������\��������̂ŁA��̗v�f���Ō�ɂ��邩��ɒ��ׂ�

	if (this->at(FIELD_H*FIELD_W - 1)) return false;	//�Ō�̗v�f����łȂ��Ȃ�p�Y���͖������ł��邱�Ƃ��m��

	for (int i = 0; i < FIELD_H*FIELD_W - 1; i++){
		if ((*this)[i]->num() != i + 1) return false;		
	}
	return true;
}

void Field::Shuffle(const int shuffle_times)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distDirection(0, 3);

	for (int i = 0; i < shuffle_times; i++){
		const int directionNum = distDirection(mt);
		switch (directionNum)
		{
		case 0:
			MoveLeftToBlank();
			break;
		case 1:
			MoveUpToBlank();
			break;
		case 2:
			MoveRightToBlank();
			break;
		case 3:
			MoveDownToBlank();
			break;
		default:
			break;
		}
	}
}

const int Field::getBlankPosition() const
{

	return _blankPosision;
}

bool Field::CheckBlankOnLeftEdge() const
{
	const int pos = this->getBlankPosition();
	if (pos%FIELD_W==0) return true;
	return false;
}

bool Field::CheckBlankOnTopEdge() const
{
	const int pos = this->getBlankPosition();
	if (pos < FIELD_W) return true;
	return false;
}

bool Field::CheckBlankOnRightEdge() const
{
	const int pos = this->getBlankPosition();
	if ((pos+1)%FIELD_W==0) return true;
	return false;
}

bool Field::CheckBlankOnBottomEdge() const
{
	const int pos = this->getBlankPosition();
	if (FIELD_W*(FIELD_H - 1) <= pos && pos < FIELD_W*FIELD_H) return true;
	else return false;
}

///�ړ������������ꍇ��true���A�����łȂ��ꍇ��false��Ԃ��B
bool Field::MoveLeftToBlank()
{
	bool isPossible = !(this->CheckBlankOnRightEdge());
	if (!isPossible){
		return false;
	}

	const int currBlankPos = this->getBlankPosition();
	const int nextBlankPos = currBlankPos + 1;
	this->Swap(currBlankPos, nextBlankPos);
	return true;
}

///�ړ������������ꍇ��true���A�����łȂ��ꍇ��false��Ԃ��B
bool Field::MoveUpToBlank()
{
	bool isPossible = !(this->CheckBlankOnBottomEdge());
	if (!isPossible){
		return false;
	}

	const int currBlankPos = this->getBlankPosition();
	const int nextBlankPos = currBlankPos + FIELD_W;
	this->Swap(currBlankPos, nextBlankPos);
	return true;
}

///�ړ������������ꍇ��true���A�����łȂ��ꍇ��false��Ԃ��B
bool Field::MoveRightToBlank()
{
	bool isPossible = !(this->CheckBlankOnLeftEdge());
	if (!isPossible){
		return false;
	}

	const int currBlankPos = this->getBlankPosition();
	const int nextBlankPos = currBlankPos - 1;
	this->Swap(currBlankPos, nextBlankPos);
	return true;
}

///�ړ������������ꍇ��true���A�����łȂ��ꍇ��false��Ԃ��B
bool Field::MoveDownToBlank()
{
	bool isPossible = !(this->CheckBlankOnTopEdge());
	if (!isPossible){
		return false;
	}

	const int currBlankPos = this->getBlankPosition();
	const int nextBlankPos = currBlankPos - FIELD_W;
	this->Swap(currBlankPos, nextBlankPos);
	return true;
}
//*************************************************************************

FieldDrawer::FieldDrawer(std::shared_ptr<Field> sp_field)
: _sp_field(sp_field)
{
}

FieldDrawer::~FieldDrawer()
{
}

std::shared_ptr<Field> FieldDrawer::getSpField() const
{
	return _sp_field;
}