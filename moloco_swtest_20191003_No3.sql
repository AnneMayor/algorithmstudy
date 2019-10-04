-- Question No1.
select site_id, count(distinct user_id)
from tb_Q3
where country_id = 'BDV'
group by site_id;

-- Qustion No2.(Modify Required)
select t1.site_id, t1.user_id
from tb_Q3 t1
inner join
(
  select site_id, user_id
  from tb_Q3
  where ts between '2019-02-03 00:00:00' and '2019-02-04 23:59:59'
  group by user_id
) t2
on t1.site_id = t2.site_id;

-- Question No3(Modify Required).
select t1.site_id, t2.mxdate, t1.user_id
from tb_Q3 t1
inner join
(
  select max(ts) mxdate, user_id
  from tb_Q3
  group by user_id
) t2
  on t1.user_id = t2.user_id
  and t1.ts = t2.mxdate;

-- Question No4.
select count(distinct user_id)
from tb_Q3
where site_id = (select site_id from tb_Q3 where ts = (select max(ts) from tb_Q3)) = site_id = (select site_id from tb_Q3 where ts = (select min(ts) from tb_Q3));
