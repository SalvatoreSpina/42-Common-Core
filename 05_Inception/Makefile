HOME=/home/sspina

all: hosts rvolumes volumes build up

hosts:
	@sudo sed -i "s/localhost/sspina.42.fr/g" /etc/hosts

rvolumes:
	sudo rm -rf $(HOME)/data

volumes:
	mkdir -p $(HOME)/data/www-data
	mkdir -p $(HOME)/data/backup-data
	mkdir -p $(HOME)/data/db-data

build:
	docker-compose -f ./infrastructure/docker-compose.yml build

up:
	@docker-compose -f ./infrastructure/docker-compose.yml up -d

rm: rvolumes down
	docker system prune -a
	
down:
	docker-compose -f ./infrastructure/docker-compose.yml down