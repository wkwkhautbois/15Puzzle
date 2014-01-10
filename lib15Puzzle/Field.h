#pragma once
#include <memory>
#include <array>

namespace Puzzle15
{
	//constexprのサポートで場合分け(msvc以外ならconstexprをサポートしていると仮定)
#if (_MSC_VER<=1800)
	#define FIELD_H 4
	#define FIELD_W 4
#else
	constexpr int FIELD_H = 4;
	constexpr int FIELD_W = 4;
#endif

	class Block
	{
	private:
		int _num;

	private:
		Block();
	public:
		Block(int num);
		virtual ~Block();
		const int num() const;
		const bool operator==(const Block& rhs) const;
	};

	class Field
	{
	private:
		std::array<std::unique_ptr<Block>, FIELD_W*FIELD_H> _blocks;
		int _blankPosision;
	public:
		Field();
		~Field();
		void Initialize();
		const std::unique_ptr<Block>& operator[](int index) const;
		const std::unique_ptr<Block>& at(int index) const;
		void Swap(int idx1, int idx2);
		bool CheckComplete() const;
		void Shuffle(const int shuffle_times = 200);

		const int getBlankPosition() const;
		bool CheckBlankOnLeftEdge() const;
		bool CheckBlankOnTopEdge() const;
		bool CheckBlankOnRightEdge() const;
		bool CheckBlankOnBottomEdge() const;

		bool MoveLeftToBlank();
		bool MoveUpToBlank();
		bool MoveRightToBlank();
		bool MoveDownToBlank();
	};

	

	class FieldDrawer
	{
	protected:
		std::shared_ptr<Field> _sp_field;
	
	private:
		FieldDrawer();
	public:
		FieldDrawer(std::shared_ptr<Field> sp_field);
		virtual ~FieldDrawer();
		virtual void Draw() = 0;
		std::shared_ptr<Field> getSpField() const;
	};

}