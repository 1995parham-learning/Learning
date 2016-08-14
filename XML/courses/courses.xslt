<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:output method="html" />

	<xsl:template match="/">
		<html>
			<body>
				<h1>Welcome to our courses :)</h1>
				<xsl:apply-templates select="//course"></xsl:apply-templates>
				<table>
					<tr>
						<th>Name</th>
						<th>Family</th>
						<th>Grade</th>
						<th>Number</th>
					</tr>
					<xsl:apply-templates select="//student"></xsl:apply-templates>
				</table>
			</body>
		</html>
	</xsl:template>

	<xsl:template match="course">
		<h2>
			<xsl:value-of select="./name"></xsl:value-of>
		</h2>
		<h3>
			<xsl:value-of select="./semester"></xsl:value-of>
		</h3>
	</xsl:template>

	<xsl:template match="student">
		<tr>
			<td><xsl:value-of select="./name"></xsl:value-of></td>
			<td><xsl:value-of select="./family"></xsl:value-of></td>
			<td><xsl:value-of select="./number"></xsl:value-of></td>
			<xsl:choose>
				<xsl:when test="./grade &lt; 10">
					<td style="background-color:red">
						<xsl:value-of select="./grade"></xsl:value-of>
					</td>
				</xsl:when>
				<xsl:otherwise>
					<td>
						<xsl:value-of select="./grade"></xsl:value-of>
					</td>
				</xsl:otherwise>
			</xsl:choose>
		</tr>
	</xsl:template>

</xsl:stylesheet>
