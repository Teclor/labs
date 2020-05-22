using System;

namespace delegates
{
    class Item
    {
        private string name;
        private double price;
        private double quantity;
        private DateTime expiration;
        public Item()
        {
            name = "unknown";
            price = 0;
            quantity = 0;
            expiration = new DateTime();
        }
        public Item(string n, double p, double q, DateTime e)
        {
            name = n;
            price = p;
            quantity = q;
            expiration = e;
        }

        public void Show()
        {
            Console.WriteLine($"Название товара: {name}; \nЦена: {price} рублей; \nКоличество: {quantity} штук(и);\nДата истечения срока годности: {expiration.ToShortDateString()}; \n");
        }
        //метод сравнения в общем случае, по переданному полю
        static public bool Compare(Item first, Item second, string field)
        {
            switch (field)
            {
                case "name": return string.Compare(first.name, second.name) >= 0 ? true : false;
                case "price": return first.price >= second.price;
                case "quantity": return first.quantity >= second.quantity;
                case "expiration": return first.expiration >= second.expiration;
                default: return false;
            }
        }
        //методы сравнения в отдельных случаях, для демонстрации делегата
        static public bool CompareName(Item first, Item second)
        {
            return string.Compare(first.name, second.name) >= 0 ? true : false;
        }
        static public bool ComparePrice(Item first, Item second)
        {
            return first.price >= second.price;
        }
        static public bool CompareQuantity(Item first, Item second)
        {
            return first.quantity >= second.quantity;
        }
        static public bool CompareExpiration(Item first, Item second)
        {
            return first.expiration >= second.expiration;
        }

    }
    class Program
    {
        delegate bool Compare(Item first, Item second);
        delegate void SortFunction(Item[] items, string sortType);

        static void Sort(Item[] items, string sortType)
        {
            // делегат статической функции сравнения класса Item
            Compare isBigger;
            switch (sortType)
            {
                case "name": isBigger = Item.CompareName; break;
                case "price": isBigger = Item.ComparePrice; break;
                case "quantity": isBigger = Item.CompareQuantity; break;
                case "expiration": isBigger = Item.CompareExpiration; break;
                default: return;
            }

            int n = items.Length;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if((j+1 < n) && isBigger(items[j],items[j+1]))
                    {
                        Item temp = new Item();
                        temp = items[j];
                        items[j] = items[j + 1];
                        items[j + 1] = temp;
                    }

        }
        static void Main(string[] args)
        {
            Item[] items = new Item[5];
            items[0] = new Item("Кефир", 30, 5, new DateTime(2020, 05, 25));
            items[1] = new Item("Молоко", 25, 28, new DateTime(2020, 05, 23));
            items[2] = new Item("Йогурт", 15, 7, new DateTime(2020, 05, 30));
            items[3] = new Item("Творог", 60, 3, new DateTime(2020, 06, 15));
            items[4] = new Item("Сыр", 90, 17, new DateTime(2020, 07, 05));

            string[] sortTypes = { "name", "price", "quantity", "expiration" };
            Console.WriteLine("Неотсортированные товары:\n");
            foreach (Item item in items)
            {
                item.Show();
            }
            //делегат функции сортировки
            SortFunction sort = Sort;

            foreach (string type in sortTypes)
            {
                Console.WriteLine("-------------------------------------NextSort--------------------------------------");
                sort(items, type);
                Console.WriteLine($"Товары отсортированные по полю {(type == "name" ? "\'название товара\'" : (type == "price" ? "\'цена\'" : (type == "quantity" ? "\'количество\'" : "\'дата истечения срока годности\'")))}:\n");
                foreach (Item item in items)
                {
                    item.Show();
                }
            }


        }
    }
}
