#ifndef SHOP_H_
#define SHOP_H_

class ShopScene 
{
	private:

	public:
		ShopScene();
		~ShopScene();

		void sceneItem() const;
		void buyItem();
		void saleItem();

		void buyMessage(int index);
		void saleMessage(int index);
		void listMessage() const;
};

#endif