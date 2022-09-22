# Write your MySQL query statement below
select P.product_id, P.product_name
from Product P join Sales S on P.product_id = S.product_id
group by S.product_id
having max(S.sale_date) <= '2019-03-31' and min(S.sale_date) >='2019-01-01'