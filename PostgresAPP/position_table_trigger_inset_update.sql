CREATE OR REPLACE FUNCTION position_check_fields_trigger()
RETURNS TRIGGER AS $$
BEGIN
	IF (NEW.name IS NULL) THEN
		RAISE EXCEPTION 'Не заполнено название должности';
	END IF;
	IF ((NEW.salary IS NULL) OR (NEW.salary::text  !~ '^[0-9]{1,9}$')) THEN
		NEW.salary = 0;
	END IF;
	RETURN NEW;
END; $$ LANGUAGE plpgsql;
CREATE TRIGGER position_before_insert BEFORE INSERT ON position FOR EACH ROW EXECUTE FUNCTION position_check_fields_trigger();
CREATE TRIGGER position_before_update BEFORE UPDATE ON position FOR EACH ROW EXECUTE FUNCTION position_check_fields_trigger();

CREATE OR REPLACE FUNCTION calculate_average_salary_per_department()
RETURNS TABLE (department_name VARCHAR, average_salary FLOAT) AS $$
	SELECT d.name AS department_name, AVG(salary) AS average_salary FROM department as d
	INNER JOIN user_department_position AS udp ON (d.id = udp.department_id)
	INNER JOIN position as p ON (udp.position_id = p.id)
	GROUP BY d.name;
$$ LANGUAGE SQL;





SELECT DISTINCT p.name as position_name FROM user_department_position as udp
INNER JOIN position AS p ON (p.id = udp.position_id);
