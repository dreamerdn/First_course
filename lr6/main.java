

class Main {
	public static void main(String[] args) {
		MyPrinter printer = new MyPrinter();
		String message = String.join(" ", args);
		printer.print(message);
	}
}
