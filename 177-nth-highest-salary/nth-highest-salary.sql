CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set n = n-1;
  RETURN (
    select distinct salary 
    from employee 
    order by salary DESC 
    Limit 1 offset N
  );
END