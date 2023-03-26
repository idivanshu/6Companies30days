//SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.9;
import "@openzeppelin/contracts/utils/Strings.sol";

contract Uid {
    mapping (address => uint256) private balances;
    mapping (address => uint256) private attempts;
    uint256 private constant fee = 1000000000000000; // in wei

    event Uid__BalanceAdded(address indexed sender, uint256 attempts);
    event Uid__Verify(address indexed sender, bytes32 Upin, bytes32 hash);

    function adh_pin(uint256 adhaarNum,  uint256 pin) internal pure returns (bytes32) {
        uint256 num = adhaarNum+ pin;
        string memory num2 = Strings.toString(num);
        bytes32 hash = sha256(abi.encodePacked(num2));
        return hash;
    }
    
    function demography( string memory name, string memory city, string memory date) internal pure returns (bytes32) {
        string memory str = string(abi.encodePacked(name, city, date));
        bytes32 hash = sha256(abi.encodePacked(str));
        return hash;
    }

    
    function addBalance() public payable {
        require(msg.value>=1000000000000000);
        balances[msg.sender] += msg.value;
        attempts[msg.sender]+= msg.value/fee;
        emit Uid__BalanceAdded(msg.sender,attempts[msg.sender]);
    }

    function getBalance(address addr) public view returns (uint256) {
        return balances[addr];
    }

    function getAttempts(address addr) public view returns (uint256) {
        return attempts[addr];
    }

    function verify(uint256 adhaarNum, uint256 pin,string memory name, string memory city, string memory date) public returns(bytes32, bytes32) {
        require(attempts[msg.sender]>0);
        attempts[msg.sender]--;
        balances[msg.sender]-=1000000000000000;

        bytes32 Upin = adh_pin(adhaarNum,pin);
        bytes32 hash = demography(name,city,date);
        emit Uid__Verify(msg.sender,Upin,hash);
        return (Upin,hash);
    }
}
