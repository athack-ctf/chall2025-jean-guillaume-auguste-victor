FROM alpine:3.19

RUN apk add --no-cache gcc musl-dev make

COPY ./src /app

WORKDIR /app

RUN make

EXPOSE 2025

# Command to run the server
CMD ["./main"]