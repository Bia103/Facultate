select round(avg(commission_pct),2)
from employees;

select round(avg(nvl(commission_pct,0)),2)
from employees;

select round(sum(commission_pct)/count(employee_id),2)
from employees;

select max(commission_pct)
 from employees;
 
 select count(*)  -- numara toate inregistrarile
from employees;

select *
from exemplu;

select count(nr)
from exemplu;

select sum(nr)
from exemplu;

select count(null)
from dual;

select max(salary), min(salary), sum(salary), avg(salary)
from employees;

SELECT MIN(salary) Minim, MAX(salary) Maxim,
       SUM(salary) Suma, ROUND(AVG(salary)) Media
FROM   employees;


select min(salary), max(salary), sum(salary), avg(salary)
from employees
group by job_id;

select count(distinct manager_id) Manageri
from employees;

select department_name,location_id,count(employee_id) nr,
round(avg(salary),2) medie
from employees  join departments using(department_id)
group by department_name,location_id;

select manager_id, min(salary)
from employees
where manager_id is not null
group by manager_id
having min(salary)>1000
order by 2 desc;

select department_id, department_name, max(salary)
from employees join departments using(department_id)
--where max(salary)>3000 Fundamental GRESIT!!!
group by department_id, department_name
having max(salary)>3000;

select employee_id,last_name,salary
from employees
where salary > (select avg(salary)
                from employees);
                
select employee_id, min(salary)
from employees
where min(salary > 1000;
/*group by manager_id
having min(salary)>1000
order by 2 desc;*/

select department_id, max(salary)
from employees
group by department_id
having min(salary)>1000
order by 2 desc;




select department_id, min(salary)
from employees
where department_id is not null and min(salary)>1000;
/*group by department_id
having min(salary)>1000
order by 2 desc;*/

select department_id, department_name, count(employee_id)
from employees 
right join departments using (department_id)
group by department_id, department_name
having count(employee_id) < 4;

select distinct department_id
from employees
where department_id > 60;

select department_id, min(salary)
from employees
GROUP BY department_id
HAVING department_id > 60;