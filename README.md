# Cashier System Program <sub> by Hugo Santos </sub>

 This program is a cashier system that allows the worker keep track of everything that the costumer asked for their food. 
And each item in the menu can cause a different value at the end of the bill, so each item will have a unique price. 

Also the program will count with taxes in California, which is 7%. And the program will show the total price before taxes and after taxes. 
And if the costumer is a student, then they can get 15% discount in the total price of their food. The program counts with discount for 
students by asking them for Student ID Number.

### How the code works?

The code works just as any cashier system, it asks for what kind of meal the costumer was asking for which
is the use of input/outputs _(cin/cout)_ to adquire the costumer's request. And each kind of bools has your own
function to be called during the payment so that the whole order can be charged right, like with everything that
was added to the bowl and plus the taxes. 

![REC-20241002011319](https://github.com/user-attachments/assets/e7c30b2f-5c54-4de2-af83-07131ba58741)

Also, the code counts with a part of the system to save the orders that got completed, so that keeping track of all
the oders to avoid any mistakes that can be made by the crew. In addition, the function to save orders can also show the time 
that the order was completed by using ctime _(which I am still reading about it)_
> Well, being honest the idea of saving orders was a little tricky, because I had to do a quick search to implement that
> kind of function in my code and I am still trying to understand how it works actually(sorry).

<img width="505" alt="Screenshot 2024-10-02 at 1 48 48 AM" src="https://github.com/user-attachments/assets/33d153ff-2061-4819-8d87-62c0f85a5cd6">

Also, the code has a function that allows the cashier to delete certain items in case the costumer changes their mind about ordering,
so that making the cashier be able to "change" the source code without having to change the whole thing manually, and avoiding having to
start the order over.

VIDEO EXPLANING THE CODE WITH SLIDES TO BE ADDED.

