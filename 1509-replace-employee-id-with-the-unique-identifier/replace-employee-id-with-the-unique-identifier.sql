select EmployeeUNI.unique_id,Employees.name from Employees,EmployeeUNI where 
EmployeeUNI.id=Employees.id
union all
select null,Employees.name from Employees where 
Employees.id not in  (select id from EmployeeUNI);