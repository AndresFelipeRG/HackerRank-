

let get_rest_lst lst =
           match lst with
           | []->[]
           | x::xs -> xs

let first (lst:int list) :int =
           match lst with
           | []-> 0
           | x::xs -> x
let move elem l m r=
         let l1 = ref l
         let l2 = ref m
         let l3 = ref r

         if (first !l3 >  elem || first !l3 = 0) then
                  if first !l2 = elem then
                         l2 := get_rest_lst (!l2)
                         l3 := elem::(!l3)

                         (!l1,!l2,!l3)

                  else if first !l1 = elem then
                         l1 :=get_rest_lst (!l1)
                         l3 := elem::(!l3)

                         (!l1,!l2,!l3)
                  else
                        (!l1,!l2,!l3)


         else if (first !l2 >  elem || first !l2 = 0)  then
                  if first !l1 = elem then
                        l1 := get_rest_lst (!l1)
                        l2 := elem::(!l2)
                        (!l1,!l2,!l3)
                  else if first !l3 = elem then
                        l3 :=get_rest_lst (!l3)
                        l2 := elem::(!l2)
                        (!l1,!l2,!l3)
                  else
                        (!l1,!l2,!l3)

         else if (first !l1 >  elem || first !l1 = 0) then
                  if first !l2 = elem then
                         l2 := get_rest_lst (!l2)
                  if first !l3 = elem then
                         l3 :=get_rest_lst (!l3)
                  l1:= elem::!l1
                  (!l1,!l2,!l3)
         else
                  (!l1,!l2,!l3)


let rec can_move element stacks=
                match stacks with

                | x::xs -> if first x = element then true else can_move element xs
                | _ -> false

let hanoi_tower a b c num_elements=

          let rec helper (l:int list,m:int list, r:int list) =
                   let mutable right = r
                   let mutable left = l
                   let mutable middle = m
                   if m.Length = 0 && l.Length = 0 then

                         (left, middle,right)
                   else
                      for i in 1..(num_elements) do
                          if (can_move i [left;middle;right]) then

                                   match  (move i left middle right) with
                                   | (a, b, c) -> left <- a; middle <- b; right<- c;



                      helper (left,middle, right)





          helper (a, b, c)


let lst = [for i in 1..10 -> i]
let res7 = hanoi_tower lst [] [] 10
