package ammer;

class FFI {
  public var name:String;
  public var fields:Array<FFIField> = [];

  public function new(name:String) {
    this.name = name;
  }
}
